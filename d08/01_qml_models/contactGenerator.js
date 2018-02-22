.pragma library

WorkerScript.onMessage = function(message) {
    var contactNumber;
    for (var i = 0; i < 1000; ++i) {
        for (var j = 0; j < 100; ++j) {
            contactNumber = i * 100 + j;
            message.model.append({"name": "Contact number " + contactNumber, "number": "555 " + contactNumber});
            message.model.sync();
        }
    }
}
