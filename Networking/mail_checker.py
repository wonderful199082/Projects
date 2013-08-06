""" 
Mail Checker - A simple program which can check for your emails at a
given interval

Usage: python mail_checker.py host username password interval
e.g. python mail_checker.py pop.gmail.com user@gmail.com 123456 10

"""

import sys
import imaplib
import email
import socket
import threading
import time, os, sched


schedule = sched.scheduler(time.time, time.sleep)

def check_mail(host, username, password, ssl = 1):
    if ssl == 1:
        mail_server = imaplib.IMAP4_SSL(host)
    else:
        mail_server = imaplib.IMAP4(host)

    mail_server.login(username, password)
    mail_server.select()

    no = 1
    # search unseen mails
    resp, items = mail_server.search(None, "Unseen")
    for i in items[0].split():
        resp, data = mail_server.fetch(i, "(RFC822)")
        text = data[0][1]

        msg = email.message_from_string(text)
        ls = msg["From"].split(' ')
        strfrom = ''
        if(len(ls) == 2):
            fromname = email.Header.decode_header((ls[0]).strip('\"'))
            strfrom = 'From : ' + to_unicode(fromname[0][0], fromname[0][1]) + ls[1]
        else:
            strfrom = 'From : ' + msg["From"]
        strdate = 'Date : ' + msg["Date"]
        subject = email.Header.decode_header(msg["Subject"])
        sub = to_unicode(subject[0][0], subject[0][1])
        strsub = 'Subject : ' + sub

        print 'No : ' + str(no)
        print strfrom
        print strdate
        print strsub

        no = no + 1
    if no == 1:
        print 'No new email...'

def to_unicode(s, encoding):
    if encoding:
        return unicode(s, encoding)
    else:
        return s
        #return unicode(s, 'utf8')

def perform(inc, host, username, password):
    schedule.enter(inc, 0, perform, (inc, host, username, password))
    check_mail(host, username, password)


if __name__ == "__main__":

    host = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    inc = int(sys.argv[4])

    e = schedule.enter(inc, 1, perform, (inc, host, username, password))

    t=threading.Thread(target=schedule.run)
    t.start()
