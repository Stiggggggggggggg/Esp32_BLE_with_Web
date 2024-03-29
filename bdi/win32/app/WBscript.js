const controlButton = document.getElementById("controlButton");
const deviceNameInput = document.getElementById("deviceNameInput");
const connectionStatus = document.getElementById("connectionStatus");
controlButton.addEventListener("click", BLEManager);


async function BLEManager() {

    connectionStatus.textContent = "SEARCHING";
  
    try {
        const device = await navigator.bluetooth.requestDevice({
            // acceptAllDevices:true
            filters: [{
                services: [0xABF0]
            }]
        });
        const connectedDevice = await device.gatt.connect();
        connectionStatus.textContent = "CONNECTED";
        const Service = await connectedDevice.getPrimaryService(0xABF0);
        const Characteristic = await Service.getCharacteristic(0xABF2);
        const data = document.getElementById("data");//define a global const in our script file to get the element with id data
        // const ReceivedData = await Characteristic.readValue();
        // const DisplayedData = ReceivedData.getUint16(1,false);
        //const DisplayedData = ReceivedData;
        //const DisplayedData = String.fromCharCode(ReceivedData);
        // data.textContent = DisplayedData.toString();
        function handleNotifications(event){
            let value = event.target.value;
            let a = [];
            for (let i = 0; i < value.byteLength; i++) {
                a.push('0x' + ('00' + value.getUint8(i).toString(16)).slice(-2));
            }
            console.log(a);
            //data.textContent = String.fromCharCode(a);//only for printing letter
            data.textContent = a;
        }
        await Characteristic.startNotifications();
        Characteristic.addEventListener('characteristicvaluechanged', handleNotifications);

        //data.textContent = DisplayedData;
        //data.textContent = String.fromCharCode(DisplayedData);
    }
    catch {
        if (typeof device !== 'undefined') {
            connectionStatus.textContent = "CONNECTION FAILED";
        }
        else {
            connectionStatus.textContent = "CANCELLED"
        }
    }
}