//
//  DataProvider.h
//  DataProvider
//
//  Created by BaiChang on 16/12/14. 第一版网络请求类
//  Copyright © 2016年 BaiChang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface DataProvider : NSObject

/*
            使用说明

    框架里包含：AFNetworking、SBJSON、AFExpand，项目中请不要重复添加
    other linker flags需要设置为 -ObjC
    需要关闭Bitcode
 
 */
/*!
 * 网络请求实体类
 */
+(DataProvider *)sharedInstance;

/*!
 * 网络请求的地址（必传）
 */
@property (nonatomic,copy) NSString* RequestUrl;
/*!
 * 上传图片地址（必传）
 */
@property (nonatomic,copy) NSString* UploadImageUrl;
/*!
 * 上传视频地址（必传）
 */
@property (nonatomic,copy) NSString* UploadVideoUrl;
/*!
 * 环信网络请求的地址（必传）
 */
@property (nonatomic,copy) NSString* Hx_RequestUrl;
/*!
 * 互动网络请求的地址（必传）
 */
@property (nonatomic,copy) NSString* TrendsRequestUrl;
/*!
 * 商城网络请求的地址（必传）
 */
@property (nonatomic,copy) NSString* ShopRequestUrl;
/*!
 * 是否开启https的校验（默认关闭，如果开启Certificate必须存在）
 */
@property (nonatomic,assign) BOOL HttpsSSL;
/*!
 * 证书名称（https-cer,不带格式）
 */
@property (nonatomic,copy) NSString* Certificate;
/*!
 * Token
 */
@property (nonatomic,strong) NSString *strToken;
/*!
 * 获取Token接口（用户未授权）
 */
@property (nonatomic,strong) NSString *strSetTokenApi;
/*!
 * 获取Token接口参数（用户未授权参数）
 */
@property (nonatomic,strong) NSDictionary *dicToken;

/*!
 * 是否打印参数（上线请关闭，默认是打开）
 */
@property (nonatomic,assign) BOOL setLogOFF;
/*!
 * 请求超时（默认15，可不传）
 */
@property (nonatomic,assign) NSTimeInterval RequestTime;

/*!
 * 开启网络监听
 */
- (void)startMonitoring;

/*!
 * @abstract 网络请求
 *
 * @param api 接口地址
 * @param dicResquest 请求参数
 *
 */
- (void)Interface:(NSString *)api parameter:(NSDictionary *)dicResquest success:(void (^)(id))success failure:(void (^)(NSError *))failure;

/*!
 * @abstract 环信网络请求
 *
 * @param api 接口地址
 * @param dicResquest 请求参数
 *
 */
- (void)Hx_Interface:(NSString *)api parameter:(NSDictionary *)dicResquest success:(void (^)(id))success failure:(void (^)(NSError *))failure;

/*!
 * @abstract 互动网络请求
 *
 * @param api 接口地址
 * @param dicResquest 请求参数
 *
 */
- (void)TrendsInterface:(NSString *)api parameter:(NSDictionary *)dicResquest success:(void (^)(id))success failure:(void (^)(NSError *))failure;

/*!
 * @abstract 商城网络请求
 *
 * @param api 接口地址
 * @param dicResquest 请求参数
 *
 */
- (void)ShopInterface:(NSString *)api parameter:(NSDictionary *)dicResquest success:(void (^)(id))success failure:(void (^)(NSError *))failure;
/*!
 * @abstract 上传一张或多张图片
 *
 * @param dicImg 预留参数，可不传
 * @param imagesArray 一定要是图片对象的数组
 *
 */
- (void)UpImgesDic:(NSDictionary *)dicImg withPostedImages:(NSArray *)imagesArray success:(void (^)(id))success failure:(void (^)(NSError *))failure;

/*!
 * @abstract 上传视频
 *
 * @param dicVideo 预留参数，可不传
 * @param dataVideo 视频data
 *
 */
- (void)UpVideoDic:(NSDictionary *)dicVideo withPostedVideo:(NSData *)dataVideo success:(void (^)(id))success failure:(void (^)(NSError *))failure;


@end
