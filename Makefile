
include $(THEOS)/makefiles/common.mk

after-install::
		install.exec "killall -9 Music"

SUBPROJECTS += mitsuhamusic mitsuhaspotify mitsuhaprefs
# SUBPROJECTS += mitsuhamusic mitsuhaspringboard mitsuhaspotify mitsuhaprefs

include $(THEOS_MAKE_PATH)/aggregate.mk
