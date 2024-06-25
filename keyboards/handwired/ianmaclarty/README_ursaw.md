
* https://github.com/ianmaclarty/ik
* https://github.com/ianmaclarty/qmk_firmware/tree/master/keyboards/handwired/ianmaclarty/ik1_2

qmk compile -kb handwired/ianmaclarty/ik1_2 -km default

handwired_ianmaclarty_ik1_2_default.uf2


flashing hold down boot bottom which is left...


git submodules
==============
https://stackoverflow.com/a/1032653

If it's the first time you check-out a repo you need to use --init first:

git submodule update --init --recursive
For git 1.8.2 or above, the option --remote was added to support updating to latest tips of remote branches:

git submodule update --recursive --remote
This has the added benefit of respecting any "non default" branches specified in the .gitmodules or .git/config files (if you happen to have any, default is origin/master, in which case some of the other answers here would work as well).

For git 1.7.3 or above you can use (but the below gotchas around what update does still apply):

git submodule update --recursive
