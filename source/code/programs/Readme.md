This is where actual applications are.
We build programs here, and eventually abstract logic into more generic utility code.
Ideally we don't want different applications sharing the same code here.
Additionally, code here should be very specific to the program.  
Anything generic needs abstracted out of the directory.

Tools may include:
- useful desktop tools
- programs for my job
- fun games
- learning tools
- example programs for various libraries

anything with a main() basically





LD_PRELOAD ideas:
https://github.com/gaul/awesome-ld-preload (everything)
https://github.com/ColumPaget/enhancer (everything)
https://github.com/scriptum/libpreload (everything)
https://github.com/zardus/preeny (everything)
https://github.com/kpu/usage (process hooks)
https://github.com/tharina/heap-tracer (memory hooks)
https://github.com/linuxthor/fml (memory hooks)
https://github.com/xroche/squandersnitch (memory hooks)
https://github.com/MageSlayer/bumpmalloc (memory hooks)
https://github.com/samsk/log-malloc2 (memory hooks)
https://github.com/em-/sleepless (time hooks)
https://github.com/majek/fluxcapacitor (time hooks)
https://github.com/wolfcw/libfaketime (time hooks)
https://github.com/vi/timeskew (time hooks)
https://github.com/df7cb/sdate (time hooks)
https://github.com/gordol/ld_preload-sounds (sound memory hooks)
https://github.com/progandy/fakeuser (user hooks)
https://github.com/robn/everybody-root (user hooks)
https://github.com/whitequark/unrandom (random hooks)
https://github.com/AGWA/force-urandom  (random hooks)
https://github.com/droberson/exec-logger (execve hooks)
https://github.com/starius/nonetwork (network hooks)
http://netjail.sourceforge.net/ (network hooks)
https://github.com/jwilk/getenvy (env hooks)
https://github.com/AdamSimpson/set_pid (pid hooks)
https://github.com/smerritt/flockit (file hooks)
https://github.com/jacereda/fsatrace (file hooks)
https://github.com/stewartsmith/libeatmydata (file hooks)
https://github.com/raoz/libstfu (console hooks)
https://github.com/nchong/cudahook (cuda hooks)
https://github.com/paulproteus/whydidyouleave (exit hooks)
https://github.com/penma/explain_preload (crash info)
https://github.com/dextero/stacktracer  (crash info)
https://github.com/EvanED/jitgdb (crash info)
https://github.com/jarusified/ld_experiments

PTRACE ideas:
https://github.com/aleden/ptracetricks (everything)
https://github.com/tom-code/ptrace (everything)
https://github.com/obs145628/ptrace-tests (trace)
https://github.com/dicej/profile (profiler)
https://github.com/toddlipcon/pmp (profiler)