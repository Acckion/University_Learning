import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts


f = open("D:/Dev/疫情.txt", "r", encoding="UTF-8")
data = f.read()
f.close()
data = json.loads(data)
data_detail = data["areaTree"][0]["children"]
data_area = list()
data_confirm = list()
data_map = list()
for area in data_detail:
    if (area["name"]) == "北京":
        standard_area_name = (area["name"]) + "市"
    elif (area["name"]) == "上海":
        standard_area_name = (area["name"]) + "市"
    elif (area["name"]) == "重庆":
        standard_area_name = (area["name"]) + "市"
    elif (area["name"]) == "天津":
        standard_area_name = (area["name"]) + "市"
    elif (area["name"]) == "广西":
        standard_area_name = "广西壮族自治区"
    elif (area["name"]) == "西藏":
        standard_area_name = "西藏自治区"
    elif (area["name"]) == "新疆":
        standard_area_name = "新疆维吾尔自治区"
    elif (area["name"]) == "内蒙古":
        standard_area_name = "内蒙古自治区"
    elif (area["name"]) == "宁夏":
        standard_area_name = "宁夏回族自治区"
    else:
        standard_area_name = (area["name"]) + "省"
    data_map.append((standard_area_name, area["total"]["confirm"]))
print(data_map)

map_epidemic = Map()
data = data_map
map_epidemic.add("疫情地图", data, "china")
map_epidemic.set_global_opts(
    visualmap_opts=VisualMapOpts(
        is_show=True,
        is_piecewise=True,
        pieces=[
            {"min": 0, "max": 99, "label": "0-99人", "color": "#CCFFFF"},
            {"min": 100, "max": 99, "label": "100-99人", "color": "#CCFF66"},
            {"min": 500, "max": 4999, "label": "500-4999人", "color": "#FF9966"},
            {"min": 5000, "max": 9999, "label": "5000-9999人", "color": "#FF6666"},
            {"min": 10000, "label": "10000人以上", "color": "#CC3333"}
        ]
    )
)
map_epidemic.render("全国疫情地图.html")
