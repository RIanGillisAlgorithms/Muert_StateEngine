

//by ian.gillis
#pragma once
#ifndef identifcationContainers_H
#define identifcationContainers_H
// identificationContainers.h
// by Ian


namespace Identifiers
{
	template <class IdType, IdType DefaultValue>
	class ID
	{
	public:
		ID() { id_ = DefaultValue;	};
		ID(IdType StartsAtId) {	id_ = StartsAtId;	};
		~ID() {};
		
		void initId(IdType Id)
		{
//			//we can only execute this once
///*			static bool once = []() {
//				_id = Id;
//				return true;
//			} ();	*/		
//			static bool wasExecuted = false;
//			if (wasExecuted)
//				return;
//
//			id_ = Id;
//			wasExecuted = true;
			id_ = Id;
		}
		IdType getId()
		{
			return id_;
		}
	protected:
		IdType id_;
	};


	template <class IdType, IdType DefaultValue>
	class ID_Child
	{
	public:
		ID_Child() { id_ = DefaultValue; };
		ID_Child(IdType StartsAtId) { initId(StartsAtId); };
		~ID_Child() {};

		void initId(IdType Id)
		{
			////static bool once = []() {
			////	_id = Id;
			////	return true;
			////} ();
			//static bool wasExecuted = false;
			//if (wasExecuted)
			//	return;

			//_id = Id;
			//wasExecuted = true;
			
			//the above only works once per class
			id_ = Id;
		}
		//IdType getNextIdAndIncrement()
		//{
		//	return _id++;
		//}
		IdType getNextId()
		{
			//return the current value of _id then inc
			return id_++;
		}
	protected:
		IdType id_;
	};

	//template specializations
	// class template:
	template <class T>
	class mycontainer {
		T element;
	public:
		mycontainer(T arg) { element = arg; }
		T increase() { return ++element; }
	};

	// class template specialization:
	template <>
	class mycontainer <char> {
		char element;
	public:
		mycontainer(char arg) { element = arg; }
		char uppercase()
		{
			if ((element >= 'a') && (element <= 'z'))
				element += 'A' - 'a';
			return element;
		}
	};











	/// <summary>
	/// template to hold a reference to an Id of IdType, along with the previously set Id
	/// </summary>
	/// <typeparam name="IdType"></typeparam>
	template <class IdType>
	class ID_Ref
	{
	public:
		ID_Ref() { id_ = -1; prevId_ = -1; };
		ID_Ref(IdType CurId) { id_ = CurId; prevId_ = -1; };
		~ID_Ref() {};

		void setId(IdType ToSet)
		{
			if (id_ != ToSet)
			{
				prevId_ = id_;
				id_ = ToSet;
			}
		}
		IdType getId()
		{
			return id_;
		}
		IdType getPrevId()
		{
			return prevId_;
		}
		void unset()
		{
			setId(-1);
		}
	protected:
		IdType id_;
		IdType prevId_;
	};


	/// <summary>
	/// template to hold a reference to an Id of IdType, along with the previously set Id
	/// </summary>
	/// <typeparam name="IdType"></typeparam>
	template <class PointerType>
	class Pointer_Ref
	{
	public:
		Pointer_Ref() { id_ = nullptr; prevId_ = nullptr; };
		Pointer_Ref(PointerType CurId) { id_ = CurId; prevId_ = nullptr; };
		~Pointer_Ref() {};

		void setId(PointerType ToSet)
		{
			if (id_ != ToSet)
			{
				prevId_ = id_;
				id_ = ToSet;
			}
		}
		PointerType getId()
		{
			return id_;
		}
		PointerType getPrevId()
		{
			return prevId_;
		}
		void unset()
		{
			setId(nullptr);
		}
	protected:
		PointerType id_;
		PointerType prevId_;
	};



}






#endif