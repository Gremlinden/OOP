
class Request():
    __slots__ = ['__type', '__time', '__function', '__requestProcessed', '__answerOperatortoRequest']

    def __init__(self, type, time = None):
        self.__type = type
        self.__time = time
        self.__function = None
        self.__requestProcessed = None
        self.__answerOperatortoRequest = None

    @property
    def type(self):
        return self.__type

    @property
    def time(self):
        return self.__time

    @property
    def function(self):
        return self.__function

    @function.setter
    def function(self, function):
        self.__function = function

    @property
    def requestProcessed(self):
        return self.__requestProcessed

    @requestProcessed.setter
    def requestProcessed(self, requestProcessed):
        self.__requestProcessed = requestProcessed

    @property
    def answerOperatortoRequest(self):
        return self.__answerOperatortoRequest

    @answerOperatortoRequest.setter
    def answerOperatortoRequest(self, answerOperatortoRequest):
        self.__answerOperatortoRequest = answerOperatortoRequest