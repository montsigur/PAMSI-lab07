import tkinter as tk

class Board(tk.Canvas):
    def __init__(self, master):

        tk.Canvas.__init__(self, master, width=600, height=600)

        self.__grid = []
        
        for i in range(3):
            for j in range(3):
                self.__grid.append(self.create_rectangle(i * 200,\
                                                         j * 200,\
                                                         (i+1) * 200,\
                                                         (j+1) * 200))
        self.pack()
                
    def putSymbol(symbol):

        pass
    
class Symbol:

    def __init__(self, x, y, shape):

        self.coords = (x, y)
        self.shape = shape

class Game:

    def __init__(self, whosfirst):

        master = tk.Tk()
        
        self.__playerSymbols = []
        self.__CPUSymbols = []
        self.whosfirst = whosfirst

        self.__board = Board(master)
        self.__whosnext = whosfirst
    
    def nextMove():

        if self.__whosnext == "CPU":
            CPUplay(__board)
            self.__whosnext = "player"

        else:
            self.__whosnext = "CPU"

    def newGame(whosfirst):

        pass

    def back():

        pass

def CPUplay(board):

    x = y = 0

    wagi = []

    for i in range(1, 4):
        for j in range(1, 4):
            if board.fields[i][j] != "null":

                if (i % 2 == 0 and j % 2 == 0):
                    wagi[i][j] = 4
                elif (i % 2 != 0 and j % 2 != 0):
                    wagi[i][j] = 3
                else:
                    wagi[i][j] = 2

            else:
                wagi[i][j] = 0
    
    return (x, y)
            
if __name__ == "__main__":

    root = tk.Tk()
    B = Board(root)
    tk.mainloop()
