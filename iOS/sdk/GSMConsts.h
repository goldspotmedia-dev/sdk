#import <Foundation/Foundation.h>

typedef enum {
    kGSM_AdType_Default = 0,
    kGSM_AdType_Infeed,
    kGSM_AdType_Interstitial,
    kGSM_AdType_Overlay
} GSM_AD_TYPE;

typedef enum {
    kGSM_EventType_None = 0,
    kGSM_EventType_Prepared,
    kGSM_EventType_PlayStart,
    kGSM_EventType_PlayEnd,
    kGSM_EventType_NoAvailableAd,
    kGSM_EventType_ShowAd,
    kGSM_EventType_CloseAd,
    kGSM_EventType_Muted,
    kGSM_EventType_Unmuted,
    kGSM_EventType_MovieTapped,
    kGSM_EventType_OrieantationChange,
    kGSM_EventType_ExitFullscreen,
    kGSM_EventType_ErrorOccured,
    kGSM_EventType_BannerViewActionShouldBegin,
    kGSM_EventType_BannerViewActionDidFinish
} GSM_EVENT_TYPE;

typedef enum {
    kGSM_Error_Unknown = 0,
    kGSM_Error_IncorrectParameter,
    kGSM_Error_Disconnected,
    kGSM_Error_Timeout,
    kGSM_Error_NotPrepare,
    kGSM_Error_Parse
}GSM_ERROR_CODE;

typedef enum {
    kGSM_ControllMode_Playing = 0,
    kGSM_ControllMode_Pausing,
    kGSM_ControllMode_StillFrame,
    kGSM_ControllMode_PlayEnd
}GSM_CONTROLL_MODE;

typedef enum {
    kGSM_Orientaion_Default=0,
    kGSM_Orientaion_Portlait,
    kGSM_Orientaion_Landscape,
    kGSM_Orientaion_DependDevice
}GSM_ORIENTATION;

typedef enum {
    kGSM_Quartile_Impresstion=0,
    kGSM_Quartile_First,
    kGSM_Quartile_Midpoint,
    kGSM_Quartile_Third,
    kGSM_Quartile_Complete
}GSM_QUATILE;

#define kRegulationTime 5.0f

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 70000
#define IOS7_SDK_AVAILABLE 1
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 60000
#define IOS6_SDK_AVAILABLE 1
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
#define IOS8_SDK_AVAILABLE 1
#endif

@interface GSMConsts : NSObject

@end
