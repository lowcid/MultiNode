#ifndef NODE_H
#define NODE_H

#include <map>
//#include <stdlib.h>
#include <string>
#include "../sockets/InputSocket.h"
#include "../sockets/OutputSocket.h"
#include "../types.h"

class Node 
{
	public:
		Node(); //Todo, constructor with title, so the title must be set for each node
		~Node();
		
		std::string Title="";
		int id=0;
		void Process();
		void Process(Socket* caller);

		InputSocket* GetInputSocket(std::string name);
		std::map<std::string, InputSocket*>* GetInputSockets();
		virtual std::map<std::string, OutputSocket*>* GetOutputSockets(){return 0;} //TODO this is done to the ui can access the outputsockets. fix this is a neat way.


	protected:
		virtual void ProcessInternal(Socket* caller)=0; //TODO only processnodes can have this
		SOCKETTYPE getInput(std::string name);
		void CreateInputSocket(std::string name, SocketDrive drive, SOCKETTYPE defaultValue);
		void DeleteInputSocket(std::string name);

	private:
		std::map<std::string, InputSocket*> InputSockets;
		unsigned int frameNumber=-1;
};

#endif
