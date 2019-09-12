#coding:utf -8

import smtplib #smtp服务器
import getpass #输入密码无显示
from email.mime.text import MIMEText #邮件文本


#邮件构建
def  Packaging_context(subject,content,recver,sender):
	message = MIMEText(content,"plain","utf-8")
	
	message['Subject'] = subject #邮件标题
	message['To'] = recver #收件人
	message['From'] = sender #发件人
	
	return message;

if __name__ == '__main__':
	sender = "innovate_huazai@163.com"#发送方
	#password = input(sender+": 授权码: ")  #明文输入
	password = getpass.getpass(sender+": 授权码: ")  #密文输入
	recver = input("请输入接收方的邮箱: ")#邮件标题
	subject = input("请输入邮件标题: ")#邮件标题
	content = input("请输入邮件内容: ")
	
	message = Packaging_context(subject,content,recver,sender);
	
	smtp = smtplib.SMTP_SSL("smtp.163.com",994) #实例化smtp服务器
	smtp.login(sender,password)#发件人登录
	smtp.sendmail(sender,[recver],message.as_string()) #as_string 对 message 的消息进行了封装
