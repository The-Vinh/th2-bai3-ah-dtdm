from ._anvil_designer import Form1Template
from anvil import *

class Form1(Form1Template):
  global data
  data = []
  def __init__(self, **properties):
    # Set Form properties and Data Bindings.
    self.init_components(**properties)

    # Any code you write here will run before the form opens.

  def btn_nhap_click(self, **event_args):
    """This method is called when the button is clicked"""
    global data
    data.append(self.txt_nhap_n.text)
    self.lbl_day_so.text = self.lbl_day_so.text + " " +self.txt_nhap_n.text
    self.txt_nhap_n.text=""
    self.txt_nhap_n.focus()
    pass
  def btn_sap_xep_click(self, **event_args):
    """This method is called when the button is clicked"""
    self.lbl_day_so.text = ""
    global data
    for i in range(len(data)):
          min_index = i
          for j in range(i + 1, len(data)):
            if data[j] < data[min_index]:
              min_index = j
      
          data[i], data[min_index] = data[min_index], data[i]
    for i in range(len(data)):
      self.lbl_day_so.text = self.lbl_day_so.text + " " + data[i]
    data=[]
    pass

  def btn_xoa_click(self, **event_args):
    """This method is called when the button is clicked"""
    global data
    data.clear()
    self.lbl_day_so.text=""
    self.txt_nhap_n.focus()
    pass
