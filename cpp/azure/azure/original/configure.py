#

class Configure(xml.sax.handler.ContentHandler):
    def __init__(self,incidents):
        super().__init__()
        self.__data = {}
        self.__text = ""
        self.__incidents = incidents
        self.__incidents.clear()
        return None
    def load(self,path):
        handler = IncidentSaxHandler(self)
        parser = xml.sax.make_parser()
        parser.serContentHandler(handler)
        parser.parse(path)
        return None

if __name__ == "__main__":
    configure = Configure()
    configure.load("configure.xml")
