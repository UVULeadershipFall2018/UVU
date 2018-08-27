from array import array

class io(object):
    def load_program(self, file):
        self.read_file(file)

    def read_file(self, filename):
        with open(filename, 'rb') as file:
            self.data = array('B', file.read())  # buffer the file
