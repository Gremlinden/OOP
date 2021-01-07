from electrqueue import Queue
from visitor import Visitor
from operatr import Operator
from request import Request
from file import File
import random
import time

request1 = Request('PAYTAXES', 1)
request2 = Request('OPENBUSINESS', 1)
request3 = Request('ASKQUESTION', 1)

queue = Queue([request1, request2, request3])

operator1 = Operator('Bot1', [request1])
operator2 = Operator('Bot2', [request2])
operator3 = Operator('Bot3', [request3])

queue.addOperator(operator1)
queue.addOperator(operator2)
queue.addOperator(operator3)

queue.startWorkingDay()
for i in range(10):
    visitor = Visitor('Vis' + str(i+1), Request(queue.listrequest[random.randint(0, 2)].type))
    visitor.addFunctionRequest(File(i + 1))
    queue.addVisitor(visitor)
time.sleep(5)
queue.endWorkingDay()