/*
 * author gitKong
 *
 * 个人博客 https://gitKong.github.io
 * gitHub https://github.com/gitkong
 * cocoaChina http://code.cocoachina.com/user/
 * 简书 http://www.jianshu.com/users/fe5700cfb223/latest_articles
 * QQ 279761135
 * 微信公众号 原创技术分享
 * 喜欢就给个like 和 star 喔~
 */


#import <Foundation/Foundation.h>

#define FLDB_DEFAULT_NAME @"gitkong"
#define FLFMDBMANAGER [FLFMDBManager shareManager:FLDB_DEFAULT_NAME]
#define FLFMDBMANAGERX(DB_NAME) [FLFMDBManager shareManager:DB_NAME]

@interface FLFMDBManager : NSObject

/**
 *  @author Clarence
 *
 *  单例创建，项目唯一
 */
+ (instancetype)shareManager:(NSString *)fl_dbName;

#pragma mark 创建表
- (BOOL)fl_createTable:(NSString *)tableName Model:(Class)model;
#pragma mark 向某个表中插入数据
- (BOOL)fl_insertModel:(id)model toTable:(NSString *)tableName;
#pragma mark 根据ID搜索
- (id)fl_searchModel:(Class)modelClass byID:(NSString *)FLDBID inTable:(NSString *)tableName;
#pragma mark 搜索获得全部
- (NSArray *)fl_searchModelArr:(Class)modelClass fromTable:(NSString *)tableName;
#pragma mark 修改某条数据
- (BOOL)fl_modifyModel:(id)model byID:(NSString *)FLDBID fromTable:(NSString *)tableName;
#pragma mark 删除表
- (BOOL)fl_dropTable:(NSString *)tableName;
#pragma mark 删除数据库
- (BOOL)fl_dropDB;
#pragma mark 从某表中删除所有model
- (BOOL)fl_deleteAllModel:(Class)modelClass fromTable:(NSString *)tableName;
#pragma mark 删除指定id的model
- (BOOL)fl_deleteModel:(Class)modelClass byId:(NSString *)FLDBID fromTable:(NSString *)tableName;
#pragma mark 数据库表是否存在
- (BOOL)fl_isExitTable:(NSString *)tableName;


@end
