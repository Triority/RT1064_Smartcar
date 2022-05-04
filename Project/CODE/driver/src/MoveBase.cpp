#include "MoveBase.hpp"

MoveBase::MoveBase() {
    _goal.reached = true;
    rt_event_init(&_reachedEvent, "GoalReached", RT_IPC_FLAG_PRIO);
}

void MoveBase::set_enabled(bool enabled) {
    _enabledLoader.store(enabled);
    if (!enabled) rt_event_send(&_reachedEvent, 1);
}

bool MoveBase::get_enabled() {
    _enabledLoader.load(_enabled);
    return _enabled;
}

void MoveBase::send_goal(pose_kalman::T x, pose_kalman::T y, pose_kalman::T yaw) { _goalLoader.store({x, y, yaw, false}); }

const MoveBase::Goal& MoveBase::get_goal() {
    if (_goalLoader.load(_goal)) _new_goal = true;
    return _goal;
}

bool MoveBase::get_reached() { return get_goal().reached; }
void MoveBase::set_reached(bool reached) {
    _goal.reached = reached;
    rt_event_send(&_reachedEvent, 1);
}

bool MoveBase::wait_for_result() {
    if (!get_enabled()) return false;
    if (get_reached()) return true;
    rt_event_recv(&_reachedEvent, 1, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, RT_NULL);
    return get_enabled();
}

bool MoveBase::new_goal() {
    bool res = _new_goal;
    _new_goal = false;
    return res;
}