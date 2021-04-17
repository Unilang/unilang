# Information and various tools related to process sandboxing.
# Relevant for security and resource sharing of processes.
# Relevant or remote build systems

#sandbox(8) 
#https://man7.org/linux/man-pages/man8/sandbox.8.html

#https://blog.cloudflare.com/sandboxing-in-linux-with-zero-lines-of-code/
#cloudflare sandboxify
#https://github.com/cloudflare/sandbox


#https://ubuntu.com/core/docs/security-and-sandboxing
#snap package manager uses a sandbox

#AppArmor, Seccomp and device permissions
#When a snap is installed, it’s metadata is examined and used to derive AppArmor profiles,
#Seccomp filters and device cgroup rules, alongside traditional permissions.
#This combination provides strong application confinement and isolation

#security frameworks = SELinux & AppArmor

#https://stackoverflow.com/questions/4249063/run-an-untrusted-c-program-in-a-sandbox-in-linux-that-prevents-it-from-opening-f
#strace - ptrace
#chroot(1)
# Linux Containers and FreeBSD jails are a better alternative to chroot.

#firejail
#https://github.com/netblue30/firejail

#https://github.com/adtac/fssb

#docker containers

#virtualbox
# Qemu

#losetup(8)
#fuseext2

#"sydbox" sandbox and "pinktrace

#user mode linux
#http://user-mode-linux.sourceforge.net/
#https://man7.org/linux/man-pages/man2/prctl.2.html

#old project:
#http://sandbox.sourceforge.net/

#https://www.man7.org/linux/man-pages/man7/mount_namespaces.7.html



#https://unix.stackexchange.com/questions/237636/is-it-possible-to-fake-a-specific-path-for-a-process
#man unshare and man namespaces and man nsenter



#FAKE TEMP
#https://blog.famzah.net/2014/06/04/private-tmp-mount-per-process-in-linux/

#STEPS:
# TARGET_USER='www-data'
# TARGET_CMD='/bin/bash' # but it can be any command
# NEWTMP="$(mktemp -d)" # securely create a new empty tmp folder
 
# chown "root:$TARGET_USER" "$NEWTMP"
# chmod 770 "$NEWTMP"
 
# unshare --mount -- /bin/bash -c "mount -o bind,noexec,nosuid,nodev '$NEWTMP' /tmp && sudo -u '$TARGET_USER' $TARGET_CMD"

#https://github.com/containers/bubblewrap












#seen:
#https://unix.stackexchange.com/questions/153665/per-process-private-file-system-mount-points
#https://www.opensourceforu.com/2016/07/many-approaches-sandboxing-linux/
#https://wiki.debian.org/Sandbox