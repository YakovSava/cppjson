import cppyy

from typing import Callable

def _include():
	cppyy.include('dumper.cxx')

def dumps(to_dumps:dict={}, evaler:Callable=eval):
	try: _exec = cppyy.dbl.dumps(str(to_dumps))
	except: 
		_include()
		_exec = cppyy.dbl.dumps(str(to_dumps))
	return evaler(_exec)