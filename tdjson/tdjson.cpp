#include <nanobind/nanobind.h>
#include <td/telegram/td_json_client.h>

namespace nb = nanobind;

NB_MODULE(tdjson_ext, m) {
  m.def("td_create_client_id", &td_create_client_id, nb::call_guard<nb::gil_scoped_release>(),
        "Returns an opaque identifier of a new TDLib instance")
      .def("td_send", &td_send, nb::call_guard<nb::gil_scoped_release>(), nb::arg("client_id"), nb::arg("request"),
           "Sends request to the TDLib client. May be called from any thread")
      .def("td_receive", &td_receive, nb::call_guard<nb::gil_scoped_release>(), nb::arg("timeout"),
           "Receives incoming updates and request responses. Must not be called simultaneously from two different "
           "threads")
      .def("td_execute", &td_execute, nb::call_guard<nb::gil_scoped_release>(), nb::arg("request"),
           "Synchronously executes a TDLib request");
  // TODO: td_set_log_message_callback?
}
