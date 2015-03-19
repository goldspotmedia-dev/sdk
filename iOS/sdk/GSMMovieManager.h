#import <Foundation/Foundation.h>
#import "GSMConsts.h"
#import <UIKit/UIKit.h>

@interface GSMMovieManager : NSObject <NSURLConnectionDelegate>
{
    id delegate_;
}

@property (nonatomic, assign) id delegate;

+ (GSMMovieManager*)manager;

//サーバへ広告リクエスト
- (void) request:(NSDictionary*)adsSettings;

//JSON形式(VAST)のデータから広告生成
- (void) createAdFromJSONData:(NSData*)jsonData adsSettings:(NSDictionary*)adsSettings;

//XML形式(VAST)のデータから広告生成
- (void) createAdFromXmlData:(NSData*)xmlData  adsSettings:(NSDictionary*)adsSettings;

//指定された広告枠のView取得
- (UIView*) getZoneView:(NSString*)zoneId;

//指定された広告枠の削除
- (void) removeZone:(NSString*)zoneId;

//指定された広告の表示
- (void) showAd:(NSString*)zoneId;

//指定した広告のクローズ(Interstitial/Overlayのみ有効)
- (void) closeAd:(NSString*)zoneId;

//指定した広告の再生(infeed枠のみ有効）
- (void) playMovie:(NSString*)zoneId;

//指定した広告の一時停止(infeed枠のみ有効）
- (void) pauseMovie:(NSString*)zoneId;

//UIScrollViewのスクロールイベント連携
- (void) scrollViewDidScroll:(NSString*)zoneId scrollView:(UIScrollView *)scrollView;

//
- (void) setUseIDFA:(BOOL)useIDFA;

@end

//アプリ側で実装するDelegate
@protocol GSMMovieDelegate <NSObject>
@optional

//エラー発生
- (void) gsmErrorOccured:(NSString*)zone adtype:(GSM_AD_TYPE)adtype error:(NSError*)error;

//動画再生準備完了
- (void)gsmPrepared:(NSString*)zone adtype:(GSM_AD_TYPE)adtype;

//動画の再正開始
- (void) gsmPlayStart:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//動画の再正終了
- (void) gsmPlayEnd:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//有効な広告がなかった
- (void) gsmNoAvailableAd:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//(Interstitial)動画画面起動
- (void) gsmShowInterstitial:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//(Interstitial)動画画面終了
- (void) gsmCloseInterstitial:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//(iAd)広告画面開始
- (void) gsmiAdViewActionShouldBegin:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

//(iAd)広告画面終了
- (void) gsmiAdViewActionDidFinish:(NSString*)zone  adtype:(GSM_AD_TYPE)adtype;

@end