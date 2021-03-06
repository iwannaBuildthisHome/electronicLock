// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ELECTRONICLOCK_HPP_
#define _ELECTRONICLOCK_HPP_

/*****************************************************************************/
enum lockOn
	{
		progMode = 1, 
		workMode
	};
struct  IntegerSet;
class ElectronicLock
{
private:

    lockOn mode; 
	IntegerSet * nCode;
public:
	 lockOn GetState()
	{
		return mode;
	}
	ElectronicLock(int _code);
	~ElectronicLock();
	ElectronicLock(ElectronicLock & _lock);
	ElectronicLock & operator = ( const ElectronicLock & _lock) ;
	ElectronicLock(ElectronicLock && _lock);
	ElectronicLock & operator = (ElectronicLock && _lock);

    bool isInProgrammingMode() const;
	bool toggleProgrammingMode(int _programmingCode);
	void registerCode(int _newCode);
	void unregisterCode(int _delPrevCode);
	bool changeProgrammingCode(int _change);
	bool tryUnlocking(int _codeKey);
	bool tryUnlocking(const char * _str);
	bool  operator ==( ElectronicLock _l)const ;
	bool  operator !=( ElectronicLock _l)const ;
};
struct IntegerSet;
IntegerSet *  IntegerSetCreate();
void IntegerSetDestroy(IntegerSet * _pSet);
void IntegerSetClear(IntegerSet & _set); 
bool IntegerSetIsEmpty(const IntegerSet & _set);
int IntegerSetSize(const IntegerSet & _set);
bool IntegerSetHasKey(const IntegerSet & _set, int _key);
void IntegerSetInsertKey(IntegerSet & _set, int _key);
void IntegerSetRemoveKey(IntegerSet & _set, int _key);
bool IntegerSetEqual (const IntegerSet  & set1,const IntegerSet  & set2);
IntegerSet * IntegerSetCopy(const IntegerSet * const _pSet);




/*****************************************************************************/

#endif //  _ELECTRONICLOCK_HPP_
