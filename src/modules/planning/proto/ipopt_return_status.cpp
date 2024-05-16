#include "modules/planning/proto/ipopt_return_status.pb.h"
#ifdef CASE
#undef CASE
#endif
#define CASE(T)    \
	case (T):      \
		return #T; \
		break;

namespace apollo::planning{
	std::string IpoptReturnStatus_Name(IpoptReturnStatus val)
	{
		switch(val)
		{
			CASE(SOLVE_SUCCEEDED);
			CASE(SOLVED_TO_ACCEPTABLE_LEVEL);
			CASE(INFEASIBLE_PROBLEM_DETECTED);
			CASE(SEARCH_DIRECTION_BECOMES_TOO_SMALL);
			CASE(DIVERGIN_ITERATES);
			CASE(USER_REQUESTED_STOP);
			CASE(FEASIBLE_POINT_FOUND);
			CASE(MAXIMUM_ITERATIONS_EXCEEDED);
			CASE(RESTORATION_FAILED);
			CASE(ERROR_IN_STEP_COMPUTATION);
			CASE(NOT_ENOUGH_DEGREES_OF_FREEDOM);
			CASE(INVALID_PROGRAM_DEFINITION);
			CASE(INVALID_OPTION);
			CASE(INVALID_NUMBER_DETECTED);
			CASE(UNRECOVERABLE_EXCEPTION);
			CASE(NONIPOPT_EXCEPTION_THROWN);
			CASE(INSUFFICIENT_MEMORY);
			CASE(INTERNAL_ERROR);
		}
		return "?";
	}
	
}