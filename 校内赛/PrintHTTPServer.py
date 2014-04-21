import string
import BaseHTTPServer
class PrintHTTPHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    def do_POST(self):
        buf = 'It works'
        self.protocal_version = "HTTP/1.1" 
        self.send_response(200)
        self.send_header("Welcome", "Contect")       
        self.end_headers()
        input=open('./Printing.txt','r')
        num=input.read()
        num=string.atoi(num)+1
        input.close()
        output=open(str(num)+'.txt','w')
        output.writelines(self.rfile.readlines())
        output.close()
        output=open('./Printing.txt','w')
        output.write(num)
        output.close()
        self.wfile.write(buf)

def test(HandlerClass = PrintHTTPHandler,
         ServerClass = BaseHTTPServer.HTTPServer):
    BaseHTTPServer.test(HandlerClass, ServerClass)

