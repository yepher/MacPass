//
//  MPSettingsHelper.h
//  MacPass
//
//  Created by Michael Starke on 30.03.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Cocoa/Cocoa.h>

/* Clipboard */
APPKIT_EXTERN NSString *const kMPSettingsKeyPasteboardClearTimeout;
APPKIT_EXTERN NSString *const kMPSettingsKeyClearPasteboardOnQuit;

/* Behaviour */
APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordEncoding;
APPKIT_EXTERN NSString *const kMPSettingsKeyOpenEmptyDatabaseOnLaunch;
APPKIT_EXTERN NSString *const kMPSettingsKeyReopenLastDatabaseOnLaunch;
APPKIT_EXTERN NSString *const kMPSettingsKeyQuitOnLastWindowClose;          // Quit MacPass when the user closes the last window
APPKIT_EXTERN NSString *const kMPSettingsKeyFileChangeStrategy;

/* URL handling */
APPKIT_EXTERN NSString *const kMPSettingsKeyBrowserBundleId;

/* Autolock */
APPKIT_EXTERN NSString *const kMPSettingsKeyLockOnSleep;
APPKIT_EXTERN NSString *const kMPSettingskeyLockOnLogout;
APPKIT_EXTERN NSString *const kMPSettingsKeyIdleLockTimeOut;

/* Autosaving states */
APPKIT_EXTERN NSString *const kMPSettingsKeyShowInspector;
APPKIT_EXTERN NSString *const kMPSettingsKeyEntryTableSortDescriptors;

/* Kdb Hide/Show settings */
APPKIT_EXTERN NSString *const kMPSettingsKeyLegacyHideTitle;
APPKIT_EXTERN NSString *const kMPSettingsKeyLegacyHideUsername;
APPKIT_EXTERN NSString *const kMPSettingsKeyLegacyHidePassword;
APPKIT_EXTERN NSString *const kMPSettingsKeyLegacyHideNotes;
APPKIT_EXTERN NSString *const kMPSettingsKeyLegacyHideURL;

/* Document/Key Location store */
APPKIT_EXTERN NSString *const kMPSettingsKeyLastDatabasePath;                 // Path to the last opened Database. Workaround if users have disabled the feature in the OS
APPKIT_EXTERN NSString *const kMPSettingsKeyRememeberdKeysForDatabases;       // NSDictionary of all db file urls and the corresponding key file url
APPKIT_EXTERN NSString *const kMPSettingsKeyRememberKeyFilesForDatabases;     // YES if key files should be remembers

/* Autotype */
APPKIT_EXTERN NSString *const kMPSettingsKeySendCommandForControlKey;         // Should MacPass swap control for command. This is useful in a cross platform environment
APPKIT_EXTERN NSString *const kMPSettingsKeyEnableGlobalAutotype;             // Is Global Autotype enabled?
APPKIT_EXTERN NSString *const kMPSettingsKeyGlobalAutotypeKeyDataKey;         // The stored Data for the user defined global autotype key
APPKIT_EXTERN NSString *const kMPSettingsKeyDefaultGlobalAutotypeSequence;    // Default sequence used for Autotype
APPKIT_EXTERN NSString *const kMPSettingsKeyAutotypeMatchTitle;               // Autotype lookup includes entry title
APPKIT_EXTERN NSString *const kMPSettingsKeyAutotypeMatchURL;                 // Autotype lookup includes entry URL
APPKIT_EXTERN NSString *const kMPSettingsKeyAutotypeMatchHost;                // Autotype lookup includes host part of entry URL
APPKIT_EXTERN NSString *const kMPSettingsKeyAutotypeMatchTags;                // Autotype lookup includes tags for entries
APPKIT_EXTERN NSString *const kMPSettingsKeyAutotypeHideAccessibiltyWarning;  // Do not show an alert, when MacPass has no support for Autotype

/* Search */
APPKIT_EXTERN NSString *const kMPSettingsKeyEntrySearchFilterContext;

/* Quicklook */
APPKIT_EXTERN NSString *const kMPSettingsKeyEnableQuicklookPreview;

/* Workflow */
APPKIT_EXTERN NSString *const kMPSettingsKeyDoubleClickURLAction;
APPKIT_EXTERN NSString *const kMPSettingsKeyDoubleClickTitleAction;
APPKIT_EXTERN NSString *const kMPSettingsKeyUpdatePasswordOnTemplateEntries;

/* Plugins */
APPKIT_EXTERN NSString *const kMPSettingsKeyLoadUnsecurePlugins;            // If set to YES this will load all plugins regardless of their codesignature status
APPKIT_EXTERN NSString *const kMPSettingsKeyDisabledPlugins;                // NSArray of bundle identifiers of disabled plugins
APPKIT_EXTERN NSString *const kMPSettingsKeyLoadIncompatiblePlugins;        // If set to YES incompatible plugins (no version info, marked as incompatible, etc) will be loaded regardless

typedef NS_ENUM(NSUInteger, MPFileChangeStrategy) {
  MPFileChangeStrategyAsk,
  MPFileChangeStrategyKeepMine,
  MPFileChangeStrategyUseOther,
  MPFileChangeStrategyMerge
};

typedef NS_ENUM(NSUInteger, MPDoubleClickURLAction) {
  MPDoubleClickURLActionCopy,
  MPDoubleClickURLActionOpen,
};

typedef NS_ENUM(NSUInteger, MPDoubleClickTitleAction) {
  MPDoubleClickTitleActionInspect,
  MPDoubleClickTitleActionIgnore,
};

/* Password Generation */
APPKIT_EXTERN NSString *const kMPSettingsKeyCopyGeneratedPasswordToClipboard;
APPKIT_EXTERN NSString *const kMPSettingsKeyDefaultPasswordLength;
APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordCharacterFlags;
APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordEnsureOccurance;
APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordUseCustomString;
APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordCustomString;

APPKIT_EXTERN NSString *const kMPSettingsKeyPasswordDefaultsForEntry;


@interface MPSettingsHelper : NSObject

/**
 *  Registers all the defaults for the application
 */
+ (void)setupDefaults;

/**
 *  Brings the defaults to a current status. Removes obsolete entries.
 */
+ (void)migrateDefaults;
/**
 *  Convenience Method to create a bind path for the NSUserDefaultsController
 *
 *  @param key SettingsKey (see MPSettingsHelper.h for available keys)
 *
 *  @return NSString containing the bindpath for this property for the NSUserDefaultController
 */
+ (NSString *)defaultControllerPathForKey:(NSString *)key;

@end
