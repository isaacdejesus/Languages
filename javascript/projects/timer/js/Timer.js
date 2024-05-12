export default class Timer {
    constructor(root){
        root.innerHTML = Timer.get_html();
        this.el = {
            minutes: root.querySelector(".timer_part_minutes"),
            seconds: root.querySelector(".timer_part_seconds"),
            control: root.querySelector(".timer_btn_control"),
            reset: root.querySelector(".timer_btn_reset"),
        };
        this.interval = null;
        this.remaining_seconds = 0;

        this.el.control.addEventListener("click", () => {
            if(this.interval === null)
                this.start();
            else
                this.stop()
        });
        this.el.reset.addEventListener("click", () => {
            const input_mins = prompt("Enter number of mins:");
            if(input_mins < 60){
                this.stop();
                this.remaining_seconds = input_mins * 60;
                this.update_interface_time();
            }

        });
    }
    update_interface_time() {
        const minutes = Math.floor(this.remaining_seconds / 60);
        const seconds = this.remaining_seconds % 60;
        this.el.minutes.textContent = minutes.toString().padStart(2, "0")
        this.el.seconds.textContent = seconds.toString().padStart(2, "0")
    }

    update_interface_controls() {
        if (this.interval === null){
            this.el.control.innerHTML =  `<span class="material-icons">play_arrow</span>`;
            this.el.control.classList.add("timer_btn_start");
            this.el.control.classList.remove("timer_btn_stop");
        }
        else
        {
            this.el.control.innerHTML =  `<span class="material-icons">pause</span>`;
            this.el.control.classList.add("timer_btn_stop");
            this.el.control.classList.remove("timer_btn_start");

        }
    }

    start() {
        if(this.remaining_seconds === 0)
            return;
        this.interval = setInterval(() => {
            this.remaining_seconds--;   //reduces 1 sec every sec
            this.update_interface_time()
            if(this.remaining_seconds === 0){
                this.stop();
            }
        }, 1000);  //runs every second
        this.update_interface_controls();
    }
    stop() {
        clearInterval(this.interval);
        this.interval = null;
        this.update_interface_controls();
    }
    static get_html() {
        return `
            <span class="timer_part timer_part_minutes">00 </span> 
            <span class="timer_part">:</span> 
            <span class="timer_part timer_part_seconds">00 </span> 
            <button type="button" class="timer_btn timer_btn_control timer_btn_start">
                <span class="material-icons">play_arrow</span>
            </button>
            <button type="button" class="timer_btn timer_btn_reset">
                <span class="material-icons">timer</span>
            </button>
        `;
    }
}
