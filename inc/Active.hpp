#pragma once

struct Active : Object {
    Active(QString value);
};

struct Op : Active {
    Op(QString value);
};

struct Cmd : Active {};

struct Seq : Active {
    Seq(QString value);
};
