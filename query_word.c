import urllib.request 
import json
import urllib.parse
#Request URL
import io
import sys
sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf-8')
while 1:
    i = input("请输入要翻译的文字(---q---退出)：")
    if i=='q':
        print("退出")
        break
    url = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule"
    
    data = {}
    header = {}
    
    header["User-Agent"] = "Mozilla/5.0 (Windows NT 6.1; rv:60.0) Gecko/20100101 Firefox/60.0"
 
 
    data['action'] = 'FY_BY_CLICKBUTTION'
    data['client'] = 'fanyideskweb'
    data['doctype'] = 'json'
    data['from'] = 'AUTO'
    data['i'] = i
    data['keyfrom'] = 'fanyi.web'
    data['salt'] = '1531752128194'
    data['sign'] = '88c77b4bcd6541ac488740afd5919019'
    data['smartresult'] = 'dict'
    data['to'] = 'AUTO'
    data['typoResult'] = 'false'
    data['version'] = '2.1'
#转码,data参数如果要传必须传bytes（字节流）类型的，如果是一个字典，先用urllib.parse.urlencode()编码。
    data = urllib.parse.urlencode(data).encode("utf-8")
#打开链接
    req = urllib.request.Request(url,data,header) #Request设置,发送数据和header
    response = urllib.request.urlopen(req)
    # response = urllib.request.urlopen(url,data,head)
#转为Unicode
    html = response.read().decode("utf-8") #输出为json格式
#json文件读取
    target = json.loads(html)
#最终字典列表输出
    print(target["translateResult"][0][0]["tgt"])
