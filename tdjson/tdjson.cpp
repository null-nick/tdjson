#include <td/telegram/td_json_client.h>
#include <nanobind/nanobind.h>

NB_MODULE(tdjson_ext, m)
{
    m.def("td_create_client_id", &td_create_client_id, "Returns an opaque identifier of a new TDLib instance")
        .def("td_send", &td_send, "Sends request to the TDLib client. May be called from any thread")
        .def("td_receive", &td_receive, "Receives incoming updates and request responses. Must not be called simultaneously from two different threads")
        .def("td_execute", &td_execute, "Synchronously executes a TDLib request");
    // TODO: td_set_log_message_callback?
}
