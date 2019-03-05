# Database

## User Message Database (UsrInfo) :

表字段名|数据类型|解释
:-:|---|---
`usr_id`|INT|用户 ID (由服务器自动生成)
`usr_usrid`|VARCHAR(100)|用户名 (用户自己定义)
`usr_passwd`|VARCHAR(30)|用户密码
`usr_name`|VARCHAR(40)|用户名称
lc|?|位置信息(location)

创建数据表

```
CREATE TABLE IF NOT EXISTS UsrInfo (
	usr_id INT UNSIGNED AUTO_INCREMENT,
	usr_usrid VARCHAR(100) NOT NULL,
	usr_passwd VARCHAR(30) NOT NULL,
	usr_name VARCHAR(40) NOT NULL,
	PRIMARY KEY ( usr_id )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

## User Relationship Database:

