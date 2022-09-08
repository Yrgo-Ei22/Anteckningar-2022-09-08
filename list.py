"""
list.py: Python list demonstration.
"""

def list_print(self):
   """
   list_print: Printing content of specified list.
   """
   if len(self) == 0:
      return
   else:
      print("--------------------------------------------------------------------------------")
      for i in self:
         print(i)
      print("--------------------------------------------------------------------------------\n")
   return

def main():
   """
   main: Assigning numbers to two lists. The first list is assigned integers 0 - 9,
         the seconds list is assigned floating point numbers between 40 - 50 in
         steps on 0.5.
   """
   l1 = []
   l2 = []

   for i in range(10):
      l1.append(i)

   num = 40.0
   while num <= 50.0:
      l2.append(num)
      num += 0.5
   
   list_print(l1)
   list_print(l2)
   return

# If this file is the start script, the main function is called to start the program:
if __name__ == "__main__":
   main()
