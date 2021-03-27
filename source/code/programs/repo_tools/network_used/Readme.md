the network connections made when performing a build
a better version of:
strace -f -e trace=network ./build_everything 2>&1 | grep sin_addr
strace -f -e trace=network ./build_everything 2>&1 | grep -oP 'connect.*inet_addr\("\K[^"]+'

good to check that every network call is coming from trusted and controlled sources within an org.
strace is TOO SLOW

better alternative:
run in a docker container (which will have its own network device).  Scan that with wireshark.
get all the ip address. convert them into hostnames so its more clear what these websites are.
show them all on a map so we know how the build would work in a post-apocalyptic world