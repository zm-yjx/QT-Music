# import re
# # 爬取数据与使用正则表达式
# import requests
# # 导入requests包来作为爬虫的基础
# import time
#
# from lxml import html
# # 使用sleep函数
# from lxml import etree
#
# if __name__ == "__main__":
# # 函数入口，防止程序从模块较大的程序运行
#
#         url1 = 'https://music.163.com/#/search/m/?s=原神'
#         # file = open("C:\\Users\\33746\\Desktop\\data.txt","r",encoding='gb2312')
#         # find = file.read()
#         # file.close()
#         # print("搜寻内容："+find)
#         url2 = '&type=1'
#         url = 'https://music.163.com/#/search/m/?s=%E5%8E%9F%E7%A5%9E&type=1'
#         # 设置爬取数据网站的路由url
#         print(url)
#         header = {
#             'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
#         }
#         # User Agent，使得爬虫伪装成为正常的浏览器请求从而可以访问爬取内容
#         requests.encoding = 'utf-8'
#         response = requests.get(url=url,headers=header)
#
#         # html_content=response.content
#         # tree = html.fromstring(html_content)
#         # a_tags = tree.xpath('//a')
#         # for a in a_tags:
#         #     href = a.get('href')
#         #     print(href)
#         # 修改文件形式为utf-8的形式
#         text = response.text
#         print(text)
#         # requests包get响应格式（响应路由，响应变量名字，UA伪装机制“即是将爬虫伪装成为一个正常的浏览器，需要在网页上获取相应浏览器信息”）



# import requests
# import re
#
# url = 'https://music.163.com/discover/toplist'
# # 伪装成浏览器
# headers = {
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
# }
#
# # get请求
# response = requests.get(url, headers=headers)
# html_data = response.text
#
# info_list = re.findall('<a href="/song\?id=(.*?)">(.*?)</a>', html_data)
#
# for info in info_list:
#     music_id = info[0]
#     music_name = info[1]
#     music_url = 'http://music.163.com/song/media/outer/url?id=' + music_id
#     print(music_url)
#
#     chars = ['\\', '/', ':', '*', '?', '"', '<', '>', '|']
#     for char in chars:
#         music_name = music_name.replace(char, '_')
#         print(music_id)
# print('http://music.163.com/song/media/outer/url?id=' + '2045806409')
#     # 图片、音频、视频都属于二进制数据
#     # music_data = requests.get(music_url, headers=headers).content
#     # with open(f'C:/Users\Administrator\Desktop\音乐播放器/{music_name}.mp3', mode='wb') as f:
#     #     f.write(music_data)



# # 等待一段时间，确保页面中的JavaScript已经执行完毕
# # 这里可以根据具体情况调整等待的时间
# print("a")
# driver.implicitly_wait(10)
# print("b")
# # 获取页面中的所有超链接
# a_tags = driver.find_elements_by_tag_name('a')
#
# for a in a_tags:
#     href = a.get_attribute('href')
#     print(href)
#
# driver.quit()



from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup
import json
import re
import requests

print("开始")
driver = webdriver.Edge()
driver.get('https://music.163.com')
sleep(6)
#创建一个浏览器网页实例同时访问

cookies = []
# cookies=driver.get_cookies()
# print(driver.get_cookies())
#
# with open("cookies.txt", "w") as fp:
#     json.dump(cookies, fp)
# #当cookie失效时将该注释接触并且重新手动登录

with open('cookies.txt', 'r', encoding='utf8') as f:
    cookies = json.loads(f.read())
# #将有效的cookie数据保存到文本文件中并且可以读取
print("open cookies file")
for i in cookies:
    print(i)
    driver.add_cookie(i)
    print("hhhh")
# #将保存好的cookie数据加入到驱动中，这样浏览器实例就可以跳过登录验证步骤

print("cookies add end")
driver.refresh()
print("rebuild this demo")
driver.get('https://music.163.com/#/search/m/?s=')

while (1):

    url1 = 'https://music.163.com/#/search/m/?s='
    print("please input:")
    findname = input()
    url1=url1+findname
    driver.get(url1)
    # #加入后重新刷新界面然后对指定网页重新爬取

    driver.implicitly_wait(10)
    sleep(6)
    # #等待界面所有元素加载完成，方便后续数据爬取

    iframe = driver.find_element(By.XPATH, "//iframe[@id='g_iframe']")
    driver.switch_to.frame(iframe)
    print("find begin")
    a_tags = driver.find_elements(By.TAG_NAME, "a")
    print("find finsh")
    # #先切换到指定iframe页（该界面可以起到数据保护与分割作用），然后再使用TAG_NAME方法找到所有<a <a>标签
    b_tags = driver.find_elements(By.TAG_NAME, "b")

    for b in b_tags:
        print(b.text)
        # 以写入模式打开文本文件
        with open('C:\\Users\\33746\\Desktop\\MusicName.txt', 'a', encoding='utf-8') as file:
            # 将字符串写入文本文件
            file.write(b.text + "\n")

    music_id = []
    id = []
    idkey = 0
    find = "https://music.163.com/song.*"
    for a in a_tags:
        if a.get_attribute('href'):
            #print(a.get_attribute('href'))
            key = a.get_attribute("href")
            res = re.search(find, key)

            if res:
                print(res)

                headers = {
                    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0'
                }
                print(res.group())
                urltext = res.group()
                idtext = urltext[-10:]
                print(idtext)

                data = requests.get('http://music.163.com/song/media/outer/url?id='+idtext).content
                # driver.get(res.group())
                # sleep(1)
                # src_list = driver.find_elements(By.TAG_NAME, 'img')
                # print(src_list)
                # sleep(1)
                path = 'C:\\Users\\33746\\Desktop\\FindMusic\\'+b_tags[idkey].text+'.mp3'
                with open(path, mode='wb') as f:
                    f.write(data)
                idkey += 1
    print("ok")
    sleep(10)
    # #界面滞留两分钟方便在网页进行具体操作

driver.quit()
# #关闭浏览器
