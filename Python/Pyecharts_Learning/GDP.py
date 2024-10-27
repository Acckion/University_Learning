# 导入Pyecharts
from pyecharts.charts import Bar, Timeline
from pyecharts.options import *

# 导入文件
f = open("D:/Dev/GDP.csv", "r", encoding="ANSI")
lines = f.readlines()
f.close()

# 处理文件
lines.pop(0)
data_GDP_dict = dict()
for line in lines:
    line = line.strip()
    line = line.split(",")
    year = line[0]
    country = line[1]
    rate = float(line[2])
    # 存在当前年份则添加，不存在则新建
    try:
        data_GDP_dict[year].append((country, rate))
    except KeyError:
        data_GDP_dict[year] = []
        data_GDP_dict[year].append([country, rate])
# 按GDP排序
timeline = Timeline()
year_list = sorted(data_GDP_dict.keys())
for year in year_list:
    data_GDP_dict[year].sort(key=lambda x: x[1], reverse=True)
    data_GDP_dict[year] = data_GDP_dict[year][8::-1]
    x_data = []
    y_data = []
    for country_GDP in data_GDP_dict[year]:
        x_data.append(country_GDP[0])
        y_data.append(country_GDP[1] / 100000000)
    # 建立图标
    bar = Bar()
    bar.add_xaxis(x_data)
    bar.add_yaxis("GDP(亿)", y_data, label_opts=LabelOpts(position="right"))
    bar.reversal_axis()
    timeline.add(bar, str(year))
# 图标设置
timeline.add_schema(
    play_interval=500,
    is_timeline_show=True,
    is_auto_play=True,
    is_loop_play=True
)
timeline.render()
