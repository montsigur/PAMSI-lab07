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

    wagi = np.array([[3, 2, 3], [2, 4, 2], [3, 2, 3]])

    for i in range(3):
        for j in range(3):
            if board.fields[i][j] == "null":
                if i == 1 and j == 1:
                    for k in range(3):
                        for l in range(3):
                            if k != 1 and l != 1:
                                if board.fields[k][l] == "X" and board.fields[-k+2][-l+2] == "X":
                                    waga += 50
                                elif board.fields[k][l] == "O" and board.fields[-k+2][-l+2] == "O":
                                    waga += 100
                                elif board.fields[k][l] == "null" and board.fields[-k+2][-l+2] != "null":
                                    waga += 10
                            
                    
                elif (i != 1 and j != 1):
                    for k in [0, 1, 1]:
                        for l in [1, 0, 1]:
                            if board.fields[k][l] == "X" and board.fields[2*k][2*l] == "X":
                                waga += 100
                            elif board.fields[k][l] == "O" and board.fields[2*k][2*l] == "O":
                                waga += 200
                            elif board.fields[k][l] != "null" and board.fields[2*k][2*l] == "null" or\
                                 board.fields[k][l] == "null" and board.fields[2*k][2*l] != "null":
                                waga += 10
                    
                else:
                    
                  pass

    tictacmatrix = [["null" for i in range(3)] for j in range(3)]
              
    for i in range(3):
        for j in range(3):
            
    
    return (x, y)
            
if __name__ == "__main__":

    root = tk.Tk()
    B = Board(root)
    tk.mainloop()


def tree(tictacmatrix):

    for i in range(3):
        for j in range(3):
            if tictacmatrix[i][j] == "null":
                
