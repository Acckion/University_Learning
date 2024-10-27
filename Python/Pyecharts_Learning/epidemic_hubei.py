# 导入模块
import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts, TitleOpts


# 读取文件
f = open("D:/Dev/疫情.txt", "r", encoding="UTF-8")
data = f.read()
f.close()
# 转为json并提取湖北省数据
data = json.loads(data)
data_detail = data["areaTree"][0]["children"][6]["children"]
# 处理数据格式
data_map = list()
data_city = str()
for city in data_detail:
    if city["name"] == "恩施州":
        data_city = "恩施土家族苗族自治州"
    elif city["name"] == "神农架":
        data_city = "神农架林区"
    elif city["name"] == "境外输入":
        data_city = city["name"]
    else:
        data_city = city["name"] + "市"
    print(data_city)
    data_map.append((data_city, city["total"]["confirm"]))


# 创建地图
map_epidemic = Map()
map_epidemic.add("疫情地图", data_map, "湖北")
# 全局配置
map_epidemic.set_global_opts(
    visualmap_opts=VisualMapOpts(
        is_show=True,
        is_piecewise=True,
        pieces=[
            {"min": 0, "max": 99, "label": "0-99人", "color": "##FFFFE0"},
            {"min": 100, "max": 499, "label": "100-499人", "color": "#CCFF66"},
            {"min": 500, "max": 1999, "label": "500-1999人", "color": "#FF9966"},
            {"min": 2000, "max": 4999, "label": "2000-4999人", "color": "#FF6666"},
            {"min": 5000, "label": "5000人以上", "color": "#CC3333"}
        ]
    ),
    title_opts=TitleOpts(
        is_show=True,
        title="湖北省疫情地图",
        subtitle=f"湖北省总计确诊{data["areaTree"][0]["children"][6]["total"]["confirm"]}\n"
                 f"境外输入{data["areaTree"][0]["children"][6]["children"][2]["total"]["confirm"]}"
    )
)
map_epidemic.render("全国疫情地图.html")
