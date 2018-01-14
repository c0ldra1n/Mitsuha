include $(THEOS)/makefiles/common.mk

TWEAK_NAME = MitsuhaMusic
MitsuhaMusic_FILES = Tweak.xmi $(wildcard ../MSH*.mm) $(wildcard ../GDUnixSocket/*.m)

MitsuhaMusic_LIBRARIES += objcipc

MitsuhaMusic_CFLAGS += -D MSHMusicComponent=1 -D THEOSBUILD=1 -D HBLogError=NSLog -w
MitsuhaMusic_CFLAGS += -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
