from constant import *
import sys
import os
class Player:

    # A player is initalized with the hands having 1 finger each
    # Both of the hands are alive
    def __init__(self):
        self.hands= [1,1]
        self.left = True
        self.right = True


def ValidAttack(p1, p2, attHand,destHand):
    """Validates an attack play
    -> If any hand in an attack play is dead, this play is
    invalid
    """
    if(p1.hands[attHand] == 0):
        return False                                            
    if(p2.hands[destHand]== 0):
        return False                                            
    return True                                              

def MakeAttack(p1, p2, attHand, destHand):
    """ Make an attack of player "p1", using hand "attHand"
        on player "p2" hand "destHand"
        Return:
        -> True if the attack were made
        -> False if not
     """
    if(not ValidAttack(p1,p2,attHand,destHand)):                #Check if it's an valid attack
        print("Not Valid Play -Attack-")
        return False
        
    p2.hands[destHand]+=p1.hands[attHand]                       #Add the quantity of fingers in the hand of p1 to the hand of player p2
    p2.hands[destHand]= p2.hands[destHand]%5                    #uses % to make sure the value does not passes 5
    return True

def ValidDivide(p, hand, validate):
    """ Check if it is possible to divide "hand" of player "p".
        -> Return true if is possible
        -> Return False if not
    """
    check=False
    if(validate>=0):
        return False                                                         
    if(hand<0):
        return False

    for i in range(2): 
        if(p.hands[i]==0):
            check=True                                          #If any hand is dead, make check = "true"
            break
    
    # If the hand trying to divide is not 0, and exist some hand that is dead and
    # it's divisible by 2, it's possible to divide
    if(p.hands[hand]!=0 and check and (p.hands[hand]%2 == 0)):  
        return True                                             
                                                                
    return False                                              

def MakeDivide(p, hand):
    """ Divide the hand of a player "p" and revive the other hand
        Returns:
        -> True if the division were made succesfuly
        -> False if not
    """
    if(not ValidDivide(p,hand,-1)):
        print("Jogada Invaliada")
        return False

    for firstEmpty in range(2):
        if(p.hands[firstEmpty]==0):                             # Find the empty hand
            found = firstEmpty

    p.hands[found] = p.hands[hand]/2                            # "Revive" a mão the dead hand
    p.hands[hand] /= 2                                          # Divide the hands quantity 
    return True

def VerifyLoses(p):
    for i in range(2):  
        if(p.hands[i]!=0):
            return False
    return True

def PrintGame(p1, p2):
    sys.stdout.write("\n\tJOGADOR 2:\n")
    for i in range(2):
        sys.stdout.write(" Mão %d:\t\t"% (i+1))
    sys.stdout.write("\n")
    for i in range(2):
        for j in range (5):
            if(j < p2.hands[i]):
                sys.stdout.write("| ")
            
            else:
                sys.stdout.write("  ")
        sys.stdout.write("\t")

    sys.stdout.write("\n\n\n\tJOGADOR 1:\n")
    for i in range(2):
        sys.stdout.write("Mão %d:\t\t"%(i+1))
    
    sys.stdout.write("\n")
    for i in range(2):
        for j in range(5):
            if(j < p1.hands[i]):
                sys.stdout.write("| ")
            else:
                sys.stdout.write("  ")
        sys.stdout.write("\t")   
    sys.stdout.write("\n\n")


def Complementary(hand):
    """Returns the complementary hand of the argument"""
    if(hand==LEFT):
        return RIGHT
    else:
        return LEFT

def SimPvPGame():
    p1 = Player()
    p2 = Player()
    Round=0
    while(True):
        os.system("clear")
        PrintGame(p1,p2)
        sys.stdout.write("Jogador ")
        if(Round%2==0):
            Ataque=p1
            Defesa=p2
            sys.stdout.write("1 ")
        else:
            Ataque=p2
            Defesa=p1
            sys.stdout.write("2 ")
        sys.stdout.write("--> ")
        while(True):
            mao1 = int(input())
            mao2 = int(input())
            mao1-=1
            mao2-=1
            if(ValidAttack(Ataque,Defesa,mao1,mao2) or ValidDivide(Ataque,mao1,mao2)):
                break

        if(mao2<0):
            MakeDivide(Ataque,mao1)
        else:
            MakeAttack(Ataque,Defesa,mao1,mao2)

        if(VerifyLoses(Defesa)):
            sys.stdout.write("Acabou o jogo\n")
            break
        Round+=1