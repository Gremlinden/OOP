from electrqueue import Queue
from visitor import Visitor
from operatr import Operator, RequestType
import random

queue = Queue()

operator1 = Operator('Bot1', [RequestType.PAYTAXES])
operator2 = Operator('Bot2', [RequestType.OPENBUSINESS])
operator3 = Operator('Bot3', [RequestType.ASKQUESTION])

queue.addOperator(operator1)
queue.addOperator(operator2)
queue.addOperator(operator3)

queue.startWorkingDay()
for i in range(10):
    visitor = Visitor(RequestType(random.randint(1, 3)))
    queue.addVisitor(visitor)
queue.endWorkingDay()