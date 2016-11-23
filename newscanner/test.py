#!/usr/bin/python2.7
#Adapted test harness from James Power/Brian Malloy alltest tester.

import os, sys
import fnmatch
import subprocess
import filecmp

EXECUTABLE = os.path.join(os.getcwd(), 'run')
PY = 'python2.7'

class TestHarness :
  def __init__(self) :
  	self.noPassed = 0
  	self.noFailed = 0
  	self.makeExecutable()

  @classmethod
  def makeExecutable(cls) :
    if not os.path.isfile(EXECUTABLE):
      retcode = subprocess.call('make',shell=True)
      assert retcode==0, '\tFAILED to make the parser'

  def testCode(self, retcode, testcase):
    if retcode > 0:
      print (testcase, 'failed')
      self.noFailed += 1
    else:
      #print testcase, 'passed'
      self.noPassed += 1

  def testOneFile(self, root, filename) :
    testcase = os.path.join(root, filename)
    with open(testcase) as tc:
        print tc.readlines()
    # store out
    retval = ""
    retval2 = ""
    #check_output throws error if error code != 0
    try:
        retval = subprocess.check_output('%s %s' % (EXECUTABLE, testcase), shell=True)
        print "me: " + retval[0:-1]
    except:
        self.testCode(1, testcase)
        return
    try:
        retval2 = subprocess.check_output('%s %s' % (PY, testcase), shell=True)
        print "py: " + retval2[0:-1]
    except:
        self.testCode(1, testcase)
        return
    if retval == retval2:
        self.testCode(0, testcase)
    else:
        self.testCode(1, testcase)
    print

  def testDirectory(self, testDir):
    assert os.path.isdir(testDir), testDir + 'must be a directory'
    for root, dirs, files in os.walk( testDir ) :
      for filename in files :
        # Give manual testcases the ol' skipperoo
        if filename.endswith('.py') and "divzero" not in filename and \
           "errtilde" not in filename and "float2.py" not in filename \
           and "float.py" not in filename and "zeronegexp" not in filename\
           and "badassign" not in filename:
          self.testOneFile(root, filename)

  def runTestCases(self, testPath):
    if os.path.isdir(testPath) :
    	self.testDirectory(testPath)
    elif os.path.isfile(testPath) :
    	self.testOneFile(os.getcwd(), testPath)

  def __str__(self) :
    return '\t%d test cases Passed\n\t%d test cases Failed' % (self.noPassed, self.noFailed)


if __name__ == '__main__':
  testcases = [ ]
  if len(sys.argv) <= 1 :
    testcases = [os.path.join(os.getcwd(), 'cases')]
  else:
    testcases = sys.argv[1:]
  harness = TestHarness()

  print "\n###################"
  print "Automatic Test Cases"
  print "###################"
  for t in testcases :
    harness.runTestCases(t)

  print "\n",harness

  print "\n###################"
  print "Manual-Check Test Cases"
  print "###################"

  with open('cases/divzero.py') as tc:
      print tc.readlines()

  # div by zero
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/divzero.py'), shell=True)
  print "me: ", retval[0:-1]
  retval2 = ''
  print "py: "
  try:
    retval2 = subprocess.check_output('%s %s' % (PY, 'cases/divzero.py'), shell=True)
  except:
    pass
  #print "py:", retval2

  # negative exponent
  print
  with open('cases/errtilde.py') as tc:
    print tc.readlines()
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/errtilde.py'), shell=True)
  print "me: " + retval[0:-1]
  try:
    retval2 = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/errtilde.py'), shell=True)
  except:
    pass
  print "py: ", retval2

  print
  with open('cases/float.py') as tc:
    print tc.readlines()
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/float.py'), shell=True)
  print "me: " + retval[0:-1]
  try:
    retval2 = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/float.py'), shell=True)
  except:
    pass
  print "py: ", retval2

  print
  with open('cases/float2.py') as tc:
    print tc.readlines()
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/float2.py'), shell=True)
  print "me: " + retval[0:-1]
  try:
    retval2 = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/float2.py'), shell=True)
  except:
    pass
  print "py: ", retval2

  print
  with open('cases/zeronegexp.py') as tc:
    print tc.readlines()
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/zeronegexp.py'), shell=True)
  print "me: " + retval[0:-1]
  try:
    retval2 = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/zeronegexp.py'), shell=True)
  except:
    pass
  print "py: ", retval2

  print
  with open('cases/badassign.py') as tc:
    print tc.readlines()
  retval = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/badassign.py'), shell=True)
  print "me: " + retval[0:-1]
  try:
    retval2 = subprocess.check_output('%s %s' % (EXECUTABLE, 'cases/badassign.py'), shell=True)
  except:
    pass
  print "py: ", retval2

  print "If you got this far, things are looking good ;) Scroll up and check manual test cases, above that is automatic."
