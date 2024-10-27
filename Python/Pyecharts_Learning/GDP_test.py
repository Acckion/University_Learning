from pyecharts.charts import Bar, Timeline
from pyecharts.options import *


f = open("D:/Dev/GDP.csv", "r", encoding="ANSI")
lines = f.readlines()
f.close()
lines.pop(0)

data_bar = dict()
years = set()
for line in lines:
    line = line.strip()
    words = line.split(",")
    year = words[0]
    try:
        data_bar[year].append([words[1], float(words[2]) / 100000000])
    except KeyError:
        data_bar[year] = []
        data_bar[year].append([words[1], float(words[2]) / 100000000])

years = sorted(data_bar.keys())

timeline = Timeline()
for year in years:
    print(data_bar[year])
    data_bar[year].sort(key=lambda x: x[1], reverse=True)
    print(data_bar[year])
    data_bar[year] = data_bar[year][8::-1]
    print(data_bar[year])
    bar = Bar()
    x_list = []
    y_list = []
    for x in data_bar[year]:
        x_list.append(x[0])
        y_list.append(x[1])
    bar.add_xaxis(x_list)
    bar.add_yaxis(f"GDP(亿){year}", y_list, label_opts=LabelOpts(position="right"))
    bar.reversal_axis()
    timeline.add(bar, time_point=year)

timeline.add_schema(
    is_timeline_show=True,
    is_auto_play=True,
    is_loop_play=True,
    play_interval=500
)
timeline.render("GDP_TEST.html")



