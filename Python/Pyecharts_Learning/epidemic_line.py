import json
from pyecharts.charts import Line
from pyecharts.options import TitleOpts


# 打开并处理文件
f_us = open("D:/Dev/美国.txt", "r", encoding="UTF-8")
f_jp = open("D:/Dev/日本.txt", "r", encoding="UTF-8")
f_id = open("D:/Dev/印度.txt", "r", encoding="UTF-8")

us_data = f_us.read()
jp_data = f_jp.read()
id_data = f_id.read()

us_data = us_data.replace("jsonp_1629344292311_69436(", " ")
jp_data = jp_data.replace("jsonp_1629350871167_29498(", " ")
id_data = id_data.replace("jsonp_1629350745930_63180(", " ")

us_data = us_data[:-2]
jp_data = jp_data[:-2]
id_data = id_data[:-2]

# 转为json文件
us_dict = json.loads(us_data)
jp_dict = json.loads(jp_data)
id_dict = json.loads(id_data)

# 提取数据
us_trend_data = us_dict["data"][0]["trend"]
x_date = us_trend_data["updateDate"][:314]
us_y_confirm = us_trend_data['list'][0]['data'][:314]
# y_cure = trend_data['list'][1]['data'][:314]
# y_death = trend_data['list'][2]['data'][:314]
# y_add = trend_data['list'][3]['data'][:314]

jp_trend_data = jp_dict["data"][0]["trend"]
jp_y_confirm = jp_trend_data['list'][0]['data'][:314]
# y_cure = trend_data['list'][1]['data'][:314]
# y_death = trend_data['list'][2]['data'][:314]
# y_add = trend_data['list'][3]['data'][:314]

id_trend_data = id_dict["data"][0]["trend"]
id_y_confirm = id_trend_data['list'][0]['data'][:314]
# y_cure = trend_data['list'][1]['data'][:314]
# y_death = trend_data['list'][2]['data'][:314]
# y_add = trend_data['list'][3]['data'][:314]\

# 建立图表
line = Line()
line.add_xaxis(x_date)
line.add_yaxis('美国确诊人数', us_y_confirm)
line.add_yaxis('日本确诊人数', jp_y_confirm)
line.add_yaxis('印度确诊人数', id_y_confirm)
# line_us.add_yaxis('治愈人数', y_cure)
# line_us.add_yaxis('死亡人数', y_death)
# line_us.add_yaxis('新增人数', y_add, is_symbol_show=False)

# 图标设置
line.set_global_opts(
    title_opts=TitleOpts(
        title="疫情数据对比图",
        subtitle="美国 日本 印度",
        pos_left="center",
        pos_bottom="1%")
)

# 输出图表
line.render()
