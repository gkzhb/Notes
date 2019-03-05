# C/S 通信协议

## 格式：JSON

* 每个 JSON 都包括整形参数 `instr`，表示该条指令请求的操作

`instr`|功能
:-:|---
0|Logout
1|Login
2|Signup
3|Chat
4|Send Location
5|Add friend

## 各项请求所需参数

### Logout	`instr`: 0

空

### Login	`instr`: 1

参数|解释
:-:|---
`id`|用户名（用户注册时自行定义的）
`passwd`|登录密码

### Signup	`instr`: 2

参数|解释
:-:|---
`id`|用户名（登录时使用）
`name`|用户名称（昵称）
`passwd`|用户登录密码

### 
