include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = Mitsuha
Mitsuha_FILES = $(wildcard *.m)
Mitsuha_INSTALL_PATH = /Library/PreferenceBundles
Mitsuha_FRAMEWORKS = UIKit
Mitsuha_PRIVATE_FRAMEWORKS = Preferences
Mitsuha_EXTRA_FRAMEWORKS += Cephei CepheiPrefs

Mitsuha_LIBRARIES += colorpicker

Mitsuha_CFLAGS += -fobjc-arc

Mitsuha_LDFLAGS += -F/opt/theos/sdks/iPhoneOS9.3.sdk/System/Library/PrivateFrameworks/

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::

	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/Mitsuha.plist$(ECHO_END)
