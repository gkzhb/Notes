#!/usr/bin/python

from datetime import datetime, date, time

dt = datetime(2018, 9, 4, 12, 52, 15)
d = dt.date()
t = dt.time()
print(dt, d, t)
str = dt.strftime('%m/%d/%Y %H:%M')  # 将 datetime 格式化为字符串
dt2 = datetime.strptime('20091031', '%Y%m%d')  # 完整的格式化定义参见 《Python 数据分析》 表10-2
dt.replace(minute=0, second=0)
delta = dt2 - dt  # datetime.timedelta 类型
print (str, dt2, dt, delta)

