#ifndef I_FETCHER_H
#define I_FETCHER_H

#include <string>
#include <vector>

using namespace std;

class IFetcher
{
	public:
        virtual string GetFileNameLinkedToPosition(int position) = 0;

        virtual string GetFileNameLinkedToPosition(int position,
												std::string fetcher_directory) = 0;

		virtual int GetRelativePositionInTheMap(int position) = 0;

		virtual void SetPrefix(std::string prefix) = 0;

		virtual std::string GetPrefix() = 0;

		virtual ~IFetcher() {};

};


#endif
