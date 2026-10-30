#ifndef  RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>


class RPN
{
    private:
        std::stack<int> _numbers;
        int  _result;
        bool _isAdd;
        bool _isSub;
        bool _isDiv;
        bool _isMul;

    public:
        RPN();
        RPN ( RPN const & other );
        RPN& operator=( RPN const & other );
        ~RPN();
        bool calculation(std::string const &s);
        bool ExecuteOperation(char c);
        int  getResult() const;
};



#endif
