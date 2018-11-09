/*
 * z使用注意
 1、需要在模型中添加一个属性FLDBID，NSString类型，为了绑定对应的数据，从而进行增删改查操作。
 2、模型中属性不能有 id命名 的属性，会跟sql 的 主键id 冲突。
 3、需要插入数据库的模型不支持继承，因为根据类名来创建表，框架内部只能读取当前类的属性，其父类的属性没办法获取。
 4、修改数据库中的模型数据只能通过指定的FLDBID作为条件修改。
 5、暂时不支持模型属性动态删减，如果删了对应属性（除了FLDBID）不影响使用，但如果增加属性了，只能从新建表存储。
 6、嵌套模型暂时不支持单表处理，需要创建多张表处理。
 7、由于每次操作完毕都会主动关闭数据库，避免大量数据操作的时候出现文件读写失败问题，因此会在控制台打印 The FMDatabase <FMDatabase: 0x600000094a50> is not open. 不影响实际使用
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
+ (instancetype)shareManager:(NSString *)dbName;

#pragma mark 创建表
- (BOOL)createTable:(NSString *)tableName Model:(Class)model;
#pragma mark 向某个表中插入数据
- (BOOL)insertModel:(id)model toTable:(NSString *)tableName;
#pragma mark 根据ID搜索
- (id)searchModel:(Class)modelClass byID:(NSString *)FLDBID inTable:(NSString *)tableName;
#pragma mark 搜索获得全部
- (NSArray *)searchModelArr:(Class)modelClass fromTable:(NSString *)tableName;
#pragma mark 修改某条数据
- (BOOL)modifyModel:(id)model byID:(NSString *)FLDBID fromTable:(NSString *)tableName;
#pragma mark 删除表
- (BOOL)dropTable:(NSString *)tableName;
#pragma mark 删除数据库
- (BOOL)dropDB;
#pragma mark 从某表中删除所有model
- (BOOL)deleteAllModel:(Class)modelClass fromTable:(NSString *)tableName;
#pragma mark 删除指定id的model
- (BOOL)deleteModel:(Class)modelClass byId:(NSString *)FLDBID fromTable:(NSString *)tableName;
#pragma mark 数据库表是否存在
- (BOOL)isExitTable:(NSString *)tableName;


@end
