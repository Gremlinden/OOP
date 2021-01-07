import time

class Operator():
    __slots__ = ['__name', '__listrequest', '__clientsNumber', '__visitorWithWrongRequest', '__timeProcessingRequest']

    def __init__(self, name, listrequest):
        self.__name = name
        self.__listrequest = listrequest
        self.__clientsNumber = 0
        self.__visitorWithWrongRequest = set()
        self.__timeProcessingRequest = None

    def __del__(self):
        print('{} serve {} visitors'.format(self.__name, self.__clientsNumber))

    @property
    def listrequest(self):
        return self.__listrequest

    @property
    def clientsNumber(self):
        return self.__clientsNumber

    @property
    def visitorWithWrongRequest(self):
        return self.__visitorWithWrongRequest

    def __checkingForСorrectnesOfRequest(self, file):
        if(file > 5):
            return True
        else:
            return False

    def __requestProcessing(self, request):
        self.__clientsNumber += 1
        correct = self.__checkingForСorrectnesOfRequest(request.function.file)
        time.sleep(self.__timeProcessingRequest)
        if(correct):
            request.requestProcessed = True
            request.answerOperatortoRequest = 'File more than 5'
        else:
            request.requestProcessed = False
            request.answerOperatortoRequest = 'File less than 5'

    def checkRequestWithOperator(self, vis, queueOroperator = True):
        for request in self.__listrequest:
            if vis.request.type == request.type:
                if queueOroperator:
                    self.__timeProcessingRequest = request.time
                return True
        return False

    def __findSuitableVisitor(self, queue):
        if len(queue.electrQueue):
            vis = queue.electrQueue[0]
            index = 1
            while vis in self.__visitorWithWrongRequest and index < len(queue.electrQueue):
                vis = queue.electrQueue[index]
                index += 1
            if self.checkRequestWithOperator(vis):
                queue.removeVisitorWithWrongRequest(vis)
                queue.electrQueue.remove(vis)
                return vis
            else:
                self.__visitorWithWrongRequest.add(vis)
                return None
        else:
            return None

    def operatorisWorking(self, queue, lock):
        while queue.status:
            lock.acquire()
            vis = self.__findSuitableVisitor(queue)
            lock.release()
            if vis != None:
                self.__requestProcessing(vis.request)
        self.__visitorWithWrongRequest.clear()