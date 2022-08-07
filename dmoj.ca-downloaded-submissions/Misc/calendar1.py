heaven = ["甲", "乙", "丙","丁", "戊", "己", "庚", "辛", "壬", "癸"]
earth = ['子', '丑', '寅', '卯', '辰', '巳', '午', '未', '申', '酉', '戌', '亥']

for _ in range(int(input())):
    year = int(input()) - 1984

    print(heaven[year % 10] + earth[year % 12])