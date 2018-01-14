include $(THEOS)/makefiles/common.mk

TWEAK_NAME = MitsuhaSpotify
MitsuhaSpotify_FILES = Tweak.xmi $(wildcard ../EZAudio/*.m) $(wildcard ../EZAudio/*.c) $(wildcard ../MSH*.mm)

MitsuhaSpotify_LIBRARIES += objcipc

MitsuhaSpotify_CFLAGS += -D MSHSpotifyComponent=1 -D THEOSBUILD=1 -D HBLogError=NSLog -w
MitsuhaSpotify_CFLAGS += -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
