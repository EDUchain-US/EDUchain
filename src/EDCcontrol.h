// Copyright (c) 2015-2017 The Bitcoin Core developers
// Copyright (c) 2017 The EDC developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/**
 * Functionality for communicating with EdcGate.
 */
#ifndef BITCOIN_EDCCONTROL_H
#define BITCOIN_EDCCONTROL_H

#include <string>

#include <boost/function.hpp>
#include <boost/chrono/chrono.hpp>
#include <boost/thread.hpp>

extern const std::string DEFAULT_EDC_CONTROL;
static const bool DEFAULT_LISTEN_ONION = true;

void StartEdcControl(boost::thread_group& threadGroup);
void InterruptEdcControl();
void StopEdcControl();

#endif /* BITCOIN_EDCCONTROL_H */


