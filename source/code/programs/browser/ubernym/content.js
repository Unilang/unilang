function create_found_acronym() {
    return {
        node: {},
        elem: {},
    };
};


/* Reading from json */
function is_acronym(text,acronyms) {
    var mtext = text.replace (/[^a-z0-9+]+/gi,'');
    for (var j = 0; j < acronyms["acronyms"].length; j++){
        if (acronyms["acronyms"][j]["abbreviation"] === mtext){
            return true;
            
        }
    }
    return false;
}

function acronym_tooltip(text,acronyms) {
    var mtext = text.replace (/[^a-z0-9+]+/gi,'');
    for (var j = 0; j < acronyms["acronyms"].length; j++){
        if (acronyms["acronyms"][j]["abbreviation"] === mtext){
            return acronyms["acronyms"][j]["expanded"];
        }
    }
    return "";
}

function create_node_from_text(text,acronym_json) {
    var outer = document.createElement("span");
    var ctext = document.createTextNode("");
    var words = tokenize_node_value(text);
    
    for (var j = 0; j < words.length; j++){
         if (is_acronym(words[j],acronym_json)) {
            var outer2 = document.createElement("span");
            var gg = document.createTextNode(words[j]);
            outer2.appendChild(gg);
            outer.appendChild(outer2);
            
            var gg2 = document.createTextNode(" ");
            outer.appendChild(gg2);
         }
         else{
            var gg2 = document.createTextNode(words[j]);
            gg2.nodeValue += " ";
            outer.appendChild(gg2);
         }
    }
    return outer;
}


function span_out_acronyms(acronym_json) {
    
    var texts = get_all_text_nodes();
    for (var i = 0; i < texts.length; i++) {
        var new_node = create_node_from_text(texts[i].nodeValue,acronym_json);
        texts[i].parentNode.replaceChild(new_node,texts[i]);
    }
    
}

function get_all_text_nodes() {
    text_nodes = []
    var elements = document.body.getElementsByTagName('*');
    for (var i = 0, imax=elements.length; i < imax; i++) {
        var element = elements[i];
        for (var j = 0, jmax = element.childNodes.length; j < jmax; j++) {
            var node = element.childNodes[j];
            if (element.nodeName != "STYLE" && element.nodeName != "NOSCRIPT" && element.nodeName != "SCRIPT"){
                if (node.nodeType === Node.TEXT_NODE) {
                    text_nodes.push(node);
                }
            }
        }
    }
    return text_nodes;
}

function find_all_acronyms(acronym_json) {

    all_acronyms = []
    var elements = document.body.getElementsByTagName('*');
    for (var i = 0, imax=elements.length; i < imax; i++) {
        var element = elements[i];
        for (var j = 0, jmax = element.childNodes.length; j < jmax; j++) {
            var node = element.childNodes[j];
            if (element.nodeName != "STYLE" && element.nodeName != "NOSCRIPT" && element.nodeName != "SCRIPT"){
                if (node.nodeType === Node.TEXT_NODE) {
                    store_acronyms_in_node(node,element,all_acronyms,acronym_json);
                }
            }
        }
    }
    return all_acronyms;
}

function store_acronyms_in_node(node,element,all_acronyms,acronym_json){
        if (is_acronym(node.nodeValue,acronym_json)) {
            var found_acronym = new create_found_acronym();
            found_acronym.node = node;
            found_acronym.elem = element;
            all_acronyms.push(found_acronym);
        }
}

function tokenize_node_value(nodeValue) {
    return nodeValue.split(" ");
}

function tooltipify(found_acronyms,acronym_json) {
    for (var i = 0; i < found_acronyms.length; i++) {
        
        //create outer span to make word a tooltip
        var outer = document.createElement("span");
        outer.setAttribute('class', 'tooltip');
        
        //insert acronym
        var word = document.createTextNode(found_acronyms[i].node.nodeValue);
        outer.appendChild(word);
        
        //create inner span to make tooltip text
        var inner = document.createElement("span");
        inner.setAttribute('class', 'tooltiptext');
        
        //insert definition
        var defined = document.createTextNode(acronym_tooltip(found_acronyms[i].node.nodeValue,acronym_json));
        inner.appendChild(defined);
        outer.appendChild(inner);
        
        //change the element
        found_acronyms[i].elem.replaceChild(outer, found_acronyms[i].node);
    }
}

function rewrite_dom_via_acronyms(acronym_json) {
    span_out_acronyms(acronym_json);
    var found_acronyms = find_all_acronyms(acronym_json);
    tooltipify(found_acronyms,acronym_json);
}

function main() {
    const url = chrome.runtime.getURL('acronym.json');
    defs = fetch(url)
      .then(function(response) {
        return response.json();
    })
    .then(acronym_json => {
        rewrite_dom_via_acronyms(acronym_json);
      })
}

window.onload = function () {
    main();
}