#I like starting on the Desktop
#providing a relative path is actually important,
#because it will fail when I right click a directory (open in terminal)
cd Desktop > /dev/null 2>&1;
export UBER_LDAP_UID=thickey
export UBER_OWNER=thickey


#-------------------#
#     OH-MY-ZSH     #
#-------------------#

#set my theme and a few zsh settings
ZSH=$HOME/.oh-my-zsh
ZSH_THEME="luxe"
COMPLETION_WAITING_DOTS="true"
DISABLE_UPDATE_PROMPT="true"
HIST_STAMPS="mm/dd/yyyy"

#load all of the good zsh plugins
plugins=(
    #autoenv error about a .autoenv folder missing (I guess I was never actually using it)
    colored-man-pages
    colorize
    command-not-found
    compleat
    copydir
    copyfile
    cp
    dircycle
    dirpersist
    encode64
    extract
    emoji
    history
    kate
    safe-paste
    screen
    #tmux (errors on mac because the program is not installed)
    tmuxinator
    rand-quote
    gnu-utils
    git-extras 
    git-flow-avh
    git-flow
    git-hubflow
    git-prompt
    # git-remote-branch (errors on mac because the program is not installed)
    git
    gitfast
    gnu-utils
    jsontools
    ruby
    sublime
    zsh-syntax-highlighting
    zsh_reload
)

#-------------------#
#       PATHS       #
#-------------------#

#places where my local programs are
path+=($HOME/.bin)
path+=($HOME/bin)
path+=($HOME/.npm-packages/bin)
path+=($HOME/.local/bin)

#recursive set on ~/.bin/scripts/
#PATH=$PATH$( find $HOME/.bin/scripts/project/src/scripts -type d -printf ":%p" ); #printf doesn't seem to exist..
PATH=$PATH$( find $HOME/.bin/scripts/project/src/scripts  -type d | sed -e 's/^/:/' | tr -d '\n' );

#the last path cannot be executed from unless we add this line 
PATH=$PATH:

#at some point, we probably want to dump all of our custom scripts
#into one directory and point to that.  This will reduce the size of our
#PATH variable.  I still want to develop the scripts in a hierarchy though.


MANPATH="/usr/local/man:$MANPATH"

#-------------------#
#       OTHER       #
#-------------------#

#make sure the ssh-agent is running so I don't have to type my github/gitlab credentials
#eval "$(ssh-agent -s)" > /dev/null 2>&1;
#bad idea actually... it will spawn too many over time
#I'll leave this in here as a thing to consider if ssh is not working properly

#Preferred editor for local and remote sessions
if [[ -n $SSH_CONNECTION ]]; then
  export EDITOR='vim'
else
  export EDITOR='subl'
fi

#mandatory (brings in oh-my-zsh)
source $ZSH/oh-my-zsh.sh

# You may need to manually set your language environment (might as well)
export LANG=en_US.UTF-8
